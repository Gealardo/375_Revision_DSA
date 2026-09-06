<h2><a href="https://www.geeksforgeeks.org/problems/interesting-queries4742/1">Range Queries for At Least K Frequent</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given an integer array <strong>arr[] </strong>and &nbsp;a 2D array <strong>queries[][] </strong>of size q × 2, where each queries[i] = [l, r] represents a query on the subarray nums[l...r] (1-based indexing), and an integer k.</span></p>
<p><span style="font-size: 14pt;">For each query, find the count of distinct elements in the specified subarray that occur at least k times.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr[] = [1, 1, 2, 1, 3], queries[][] = [[1, 5], [2, 4]], k = 1
<strong>Output: </strong>[3, 2]
<strong>Explanation: </strong>For the 1st query, from l=1 to r=5, 1, 2 and 3 have the frequency at least 1.
For the second query, from l=2 to r=4, 1 and 2 have the frequency at least 1.
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr[] = [1, 2, 3, 1], queries[][] = [[1, 4], [2, 4], [4, 4], k = 2
<strong>Output: </strong>[1, 0, 0]
<strong>Explanation: </strong>For the 1st query, from l=1 to r=4, 1 has frequency 2. <br>For the second query, from l=2 to r=4, no number has frequency at least 2.
For the third query, from l=4 to r=4, no number has frequency at least 2. </span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ n, q, k ≤ 10<sup>4</sup>, where n is the size of the array<br>1 ≤ nums[i] ≤ 10<sup>3<br></sup></span><span style="font-size: 14pt;">1 ≤ queries[i][0] ≤ queries[i][1] ≤ n</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Map</code>&nbsp;<code>Sqrt Decomposition</code>&nbsp;