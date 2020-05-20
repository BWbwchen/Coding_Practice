import Control.Monad
import Data.List

main = do  
    n <- readLn :: IO Int
    replicateM_ n routine 


routine = do
    s <- getLine 
    print $ solve s

solve :: String -> Int 
solve s
    | null total_ans = 0
    | otherwise = minimum $ map (\((a, la), (b, lb), (c, lc)) -> lb+2) total_ans
    where 
        -- group_list = [(char, how_many)]
        grouped_list = map (\x -> (head x, length x)) $ group s
        -- pre_now_next = [(i-1, length), (i, length), (i+1, length)]
        pre_now_next = zip3 grouped_list (tail grouped_list) (tail $ tail $ grouped_list)
        -- total_ans = i-1 != i 's pair
        total_ans = filter (\((a, la), (b, lb), (c, lc)) -> length (nub [a, b, c]) == 3) pre_now_next
