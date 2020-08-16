import Control.Monad -- for replicateM_
import Data.List -- for sort

solve :: Int -> [Int] -> Int
solve goal xs = f xs (reverse xs) `div` 2
    where 
        f (x:xs) (y:ys)
            | x + y < goal = f xs (y:ys) 
            | x + y == goal = 1 + f xs ys
            | otherwise = f (x:xs) ys
        f _ _ = 0

deal :: IO()
deal = do 
    n <- read <$> getLine
    a <- sort . map read . words <$> getLine
    putStrLn $ show $ maximum [solve s a | s <- [2 .. 2*n]]

main :: IO()
main = getLine >>= flip replicateM_ deal . read 
