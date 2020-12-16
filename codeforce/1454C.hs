import Data.Foldable
import Data.List
 
main = do
  cas <- read <$> getLine
  mapM_ solveOneCase [1 .. cas]
 
solveOneCase _ = getLine >> getLine >>= print . solve . map read . words

solve :: [Int] -> Int
solve xs = minimum ans
    where 
        distinct = map head $ group xs
        ans = map appearTime . group . sort $ distinct
        appearTime zs@(z:z') = length zs + 1 - theTwoEnd (head distinct) z - theTwoEnd (last distinct) z
        theTwoEnd x y = if x == y then 1 else 0

{--
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
--}
