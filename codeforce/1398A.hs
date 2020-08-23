import Control.Monad -- for replicateM_
import Data.List -- for sort

solve :: [Int] -> [Int]
solve p@(x:y:xs) 
    | length xs < 1 = [-1, -1, -1]
    | x + y <= last xs = [1, 2, length p] 
    | otherwise = [-1, -1, -1]

output :: [Int] -> [String]
output [-1, -1, -1] = ["-1"]
output xs = map show xs

myshow :: [String] -> String
myshow (x:xs) 
    | null xs = x 
    | otherwise = x ++ " " ++ myshow xs

deal :: IO()
deal = do 
    getLine
    x <- map read . words <$> getLine
    putStrLn $ myshow $ output $ solve x

main :: IO()
main = getLine >>= flip replicateM_ deal . read 
