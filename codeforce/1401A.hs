import Control.Monad -- for replicateM_
import Data.List -- for sort
 
solve :: [Int] -> Int
solve (x:xs)
    | n == k = 0
    | n < k = k - n
    | otherwise = mod (n-k) 2
    where 
        n = x
        k = head xs
 
deal :: IO()
deal = do 
    x <- map read . words <$> getLine
    putStrLn $ show $ solve x
 
main :: IO()
main = getLine >>= flip replicateM_ deal . read 
