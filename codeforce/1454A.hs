import Control.Monad -- for replicateM_
import Data.List -- for sort
 
solve :: Int -> [Int]
solve n = tail $ [1..n] ++ [1]
 
listToString = unwords . map show 
 
deal :: IO()
deal = do 
    a <- readLn
    putStrLn $ listToString $ solve a
 
main :: IO()
main = getLine >>= flip replicateM_ deal . read 
