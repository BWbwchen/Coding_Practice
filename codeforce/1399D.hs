import Control.Monad -- for replicateM_
import Data.List -- for sort

{-
 -
 - meet 0 and 
 - 1. ones is empty
 -      add it to zeros.
 - 2. ones isn't empty
 -      pop ones, and add it to zeros.
 - meet 1 and 
 - 1. zeros is empty
 -      add it to ones.
 - 2. zeros isn't empty
 -      pop zeros, and add it to ones.
 -}
solve :: Int -> [Bool] -> [Int] -> [Int] -> [Int] 
solve now_id (False:xs) zeros [] = now_id : solve (now_id+1) xs (now_id:zeros) []  
solve now_id (False:xs) zeros (o:ones) = o : solve now_id  xs (o:zeros) ones 
solve now_id (True:xs) [] ones = now_id : solve (now_id+1) xs [] (now_id:ones)
solve now_id (True:xs) (z:zeros) ones = z : solve now_id  xs zeros (z:ones)
solve now_id _ _ _ = []


deal :: IO()
deal = do 
    getLine
    a <- map (== '1')  <$> getLine
    let answer = solve 1 a [] []
    print $ maximum answer
    putStrLn $ unwords $ map show answer

main :: IO()
main = getLine >>= flip replicateM_ deal . read 
