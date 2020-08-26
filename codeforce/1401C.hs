import Control.Monad -- for replicateM_
import Data.List -- for sort

solve :: [Int] -> String
solve xs = if error == 0 then "YES" else "NO"
    where 
        error = length $ filter (\(x, y) -> x /= y && mod x min_element /= 0) (zip xs sorted)
        sorted = sort xs
        min_element = minimum xs


deal :: IO()
deal = do 
    getLine
    a <- map read . words <$> getLine
    putStrLn $ solve a

main :: IO()
main = getLine >>= flip replicateM_ deal . read 
