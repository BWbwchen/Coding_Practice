import Control.Monad -- for replicateM_
import Data.List -- for sort
 
solve :: [Int] -> [Int] -> Int
solve a b = 2 * a2b1min - 2 * fuck
    where 
        a2b1min = min a2 b1
        fuck = min mya1 myb2
        a0 = head a
        a1 = last $ take 2 a
        a2 = last a
        b0 = head b
        b1 = last $ take 2 b
        b2 = last b
        mya1 = a1 - min a1 b0
        myb2 = b2 - min a0 b2
 
deal :: IO()
deal = do 
    a <- map read . words <$> getLine
    b <- map read . words <$> getLine
    putStrLn $ show $ solve a b
 
main :: IO()
main = getLine >>= flip replicateM_ deal . read
