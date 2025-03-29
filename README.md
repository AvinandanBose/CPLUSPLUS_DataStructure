# CPLUSPLUS-DataStructure
The repository will contain programs about Data Structure built on C plus plus language.

<h1> 1.Arrays </h1>

<ul>

<h2><li> Static Array</li></h2>

<ul>



<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/static_array_traversal.cpp"> 1. 𝑰𝒏𝒊𝒕𝒊𝒂𝒍𝒊𝒛𝒂𝒕𝒊𝒐𝒏 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚 and 𝑻𝒓𝒂𝒗𝒆𝒓𝒔𝒂𝒍 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚𝒔 </a></h3>

<h3><ins>𝑵𝒐𝒕𝒆</ins>: 𝒊𝒏𝒕 𝒎𝒂𝒊𝒏(𝒊𝒏𝒕 𝒂𝒓𝒈_𝒄𝒐𝒖𝒏𝒕, 𝒄𝒉𝒂𝒓 **𝒂𝒓𝒈_𝒗𝒆𝒄𝒕𝒐𝒓, 𝒄𝒉𝒂𝒓 **𝒆𝒏𝒗_𝒑𝒐𝒊𝒏𝒕𝒆𝒓) 𝒄𝒂𝒏 𝒂𝒍𝒔𝒐 𝒃𝒆 𝒘𝒓𝒊𝒕𝒕𝒆𝒏 𝒂𝒔:</h3>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/static_array_traversal1.cpp"> 1. 𝑰𝒏𝒊𝒕𝒊𝒂𝒍𝒊𝒛𝒂𝒕𝒊𝒐𝒏 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚 and 𝑻𝒓𝒂𝒗𝒆𝒓𝒔𝒂𝒍 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚𝒔(2) </a></h3>

<h3><ins>𝑻𝒉𝒂𝒕 𝒊𝒔:</ins> 𝒊𝒏𝒕 𝒎𝒂𝒊𝒏(𝒊𝒏𝒕 𝒂𝒓𝒈_𝒄𝒐𝒖𝒏𝒕, 𝒄𝒉𝒂𝒓 **𝒂𝒓𝒈_𝒗𝒆𝒄𝒕𝒐𝒓, 𝒄𝒉𝒂𝒓 **𝒆𝒏𝒗_𝒑𝒐𝒊𝒏𝒕𝒆𝒓) 𝒄𝒂𝒏 𝒂𝒍𝒔𝒐 𝒃𝒆 𝒘𝒓𝒊𝒕𝒕𝒆𝒏 𝒂𝒔: 𝒊𝒏𝒕 𝒎𝒂𝒊𝒏(𝒊𝒏𝒕 𝒂𝒓𝒈𝒄, 𝒄𝒉𝒂𝒓 *𝒂𝒓𝒈𝒗[], 𝒄𝒉𝒂𝒓 *𝒆𝒏𝒗𝒑[]) → 𝑻𝒉𝒊𝒔 𝒕𝒉𝒆 𝒆𝒙𝒂𝒄𝒕 𝒆𝒙𝒕𝒆𝒏𝒔𝒊𝒐𝒏 𝒐𝒇 𝒎𝒂𝒊𝒏 𝒇𝒖𝒏𝒄𝒕𝒊𝒐𝒏.</h3>

<ul>

<h3><li>𝒂𝒓𝒈𝒄 → 𝒂𝒓𝒈𝒄 (𝒂𝒓𝒈𝒖𝒎𝒆𝒏𝒕 𝒄𝒐𝒖𝒏𝒕) 𝒊𝒔 𝒂𝒏 𝒊𝒏𝒕𝒆𝒈𝒆𝒓 𝒕𝒉𝒂𝒕 𝒊𝒏𝒅𝒊𝒄𝒂𝒕𝒆𝒔 𝒉𝒐𝒘 𝒎𝒂𝒏𝒚 𝒂𝒓𝒈𝒖𝒎𝒆𝒏𝒕𝒔 𝒘𝒆𝒓𝒆 𝒆𝒏𝒕𝒆𝒓𝒆𝒅 𝒐𝒏 𝒕𝒉𝒆 𝒄𝒐𝒎𝒎𝒂𝒏𝒅 𝒍𝒊𝒏𝒆 𝒘𝒉𝒆𝒏 𝒕𝒉𝒆 𝒑𝒓𝒐𝒈𝒓𝒂𝒎 𝒘𝒂𝒔 𝒔𝒕𝒂𝒓𝒕𝒆𝒅. 𝑻𝒉𝒆 𝒗𝒂𝒓𝒊𝒂𝒃𝒍𝒆 𝒂𝒓𝒈𝒄 𝒏𝒆𝒗𝒆𝒓 𝒉𝒐𝒍𝒅𝒔 𝒂 𝒏𝒆𝒈𝒂𝒕𝒊𝒗𝒆 𝒗𝒂𝒍𝒖𝒆.</li> </h3>

<h3><li>𝒂𝒓𝒈𝒗 → 𝒂𝒓𝒈𝒗 (𝒂𝒓𝒈𝒖𝒎𝒆𝒏𝒕 𝒗𝒆𝒄𝒕𝒐𝒓), 𝒊𝒔 𝒂𝒏 𝒂𝒓𝒓𝒂𝒚 𝒐𝒇 𝒑𝒐𝒊𝒏𝒕𝒆𝒓𝒔 𝒕𝒐 𝒂𝒓𝒓𝒂𝒚𝒔 𝒐𝒇 𝒄𝒉𝒂𝒓𝒂𝒄𝒕𝒆𝒓 𝒐𝒃𝒋𝒆𝒄𝒕𝒔. 𝑻𝒉𝒆 𝒂𝒓𝒓𝒂𝒚 𝒐𝒃𝒋𝒆𝒄𝒕𝒔 𝒂𝒓𝒆 𝒏𝒖𝒍𝒍-𝒕𝒆𝒓𝒎𝒊𝒏𝒂𝒕𝒆𝒅 𝒔𝒕𝒓𝒊𝒏𝒈𝒔, 𝒓𝒆𝒑𝒓𝒆𝒔𝒆𝒏𝒕𝒊𝒏𝒈 𝒕𝒉𝒆 𝒂𝒓𝒈𝒖𝒎𝒆𝒏𝒕𝒔 𝒕𝒉𝒂𝒕 𝒘𝒆𝒓𝒆 𝒆𝒏𝒕𝒆𝒓𝒆𝒅 𝒐𝒏 𝒕𝒉𝒆 𝒄𝒐𝒎𝒎𝒂𝒏𝒅 𝒍𝒊𝒏𝒆 𝒘𝒉𝒆𝒏 𝒕𝒉𝒆 𝒑𝒓𝒐𝒈𝒓𝒂𝒎 𝒘𝒂𝒔 𝒔𝒕𝒂𝒓𝒕𝒆𝒅.𝑻𝒉𝒆 𝒇𝒊𝒓𝒔𝒕 𝒆𝒍𝒆𝒎𝒆𝒏𝒕 𝒐𝒇 𝒕𝒉𝒆 𝒂𝒓𝒓𝒂𝒚, 𝒂𝒓𝒈𝒗[0], 𝒊𝒔 𝒂 𝒑𝒐𝒊𝒏𝒕𝒆𝒓 𝒕𝒐 𝒕𝒉𝒆 𝒄𝒉𝒂𝒓𝒂𝒄𝒕𝒆𝒓 𝒂𝒓𝒓𝒂𝒚 𝒕𝒉𝒂𝒕 𝒄𝒐𝒏𝒕𝒂𝒊𝒏𝒔 𝒕𝒉𝒆 𝒑𝒓𝒐𝒈𝒓𝒂𝒎 𝒏𝒂𝒎𝒆 𝒐𝒓 𝒊𝒏𝒗𝒐𝒄𝒂𝒕𝒊𝒐𝒏 𝒏𝒂𝒎𝒆 𝒐𝒇 𝒕𝒉𝒆 𝒑𝒓𝒐𝒈𝒓𝒂𝒎 𝒕𝒉𝒂𝒕 𝒊𝒔 𝒃𝒆𝒊𝒏𝒈 𝒓𝒖𝒏 𝒇𝒓𝒐𝒎 𝒕𝒉𝒆 𝒄𝒐𝒎𝒎𝒂𝒏𝒅 𝒍𝒊𝒏𝒆. 𝒂𝒓𝒈𝒗[1] 𝒊𝒏𝒅𝒊𝒄𝒂𝒕𝒆𝒔 𝒕𝒉𝒆 𝒇𝒊𝒓𝒔𝒕 𝒂𝒓𝒈𝒖𝒎𝒆𝒏𝒕 𝒑𝒂𝒔𝒔𝒆𝒅 𝒕𝒐 𝒕𝒉𝒆 𝒑𝒓𝒐𝒈𝒓𝒂𝒎, 𝒂𝒓𝒈𝒗[2] 𝒕𝒉𝒆 𝒔𝒆𝒄𝒐𝒏𝒅 𝒂𝒓𝒈𝒖𝒎𝒆𝒏𝒕, 𝒂𝒏𝒅 𝒔𝒐 𝒐𝒏. </li> </h3>
<ul>
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/eg_argvargcenvp.cpp"> 𝑬𝒙𝒂𝒎𝒑𝒍𝒆 𝒐𝒇 𝒂𝒓𝒈𝒄,𝒂𝒓𝒈𝒗 𝒂𝒏𝒅 𝒆𝒏𝒗𝒑 </h3>

![Screenshot (404)](https://user-images.githubusercontent.com/38869235/235552442-cef00077-b089-4975-8591-e3e0dd46ec5f.png)

</ul>

<h3><li>𝒆𝒏𝒗𝒑 → 𝒆𝒏𝒗𝒑 𝒔𝒕𝒂𝒏𝒅𝒔 𝒇𝒐𝒓 𝒆𝒏𝒗𝒊𝒓𝒐𝒏𝒎𝒆𝒏𝒕 𝒑𝒐𝒊𝒏𝒕𝒆𝒓, 𝑰𝒕 𝒊𝒔 𝒂𝒏 𝒂𝒓𝒓𝒂𝒚 𝒐𝒇 𝒑𝒐𝒊𝒏𝒕𝒆𝒓𝒔 𝒕𝒐 𝒆𝒏𝒗𝒊𝒓𝒐𝒏𝒎𝒆𝒏𝒕 𝒗𝒂𝒓𝒊𝒂𝒃𝒍𝒆𝒔. 𝑻𝒉𝒆 𝒆𝒏𝒗𝒑 𝒂𝒓𝒓𝒂𝒚 𝒊𝒔 𝒕𝒆𝒓𝒎𝒊𝒏𝒂𝒕𝒆𝒅 𝒃𝒚 𝒂 𝒏𝒖𝒍𝒍 𝒑𝒐𝒊𝒏𝒕𝒆𝒓. </li> </h3>


</ul>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/static_array_overriding_of_ith_elem.cpp"> 2. 𝑶𝒗𝒆𝒓𝒓𝒊𝒅𝒊𝒏𝒈 𝒊𝒕𝒉 𝒆𝒍𝒆𝒎𝒆𝒏𝒕 </a></h3>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/static_array_inserting_elem.cpp"> 3. 𝑰𝒏𝒔𝒆𝒓𝒕 𝑬𝒍𝒆𝒎𝒆𝒏𝒕 𝒊𝒏 𝑨𝒓𝒓𝒂𝒚 </a></h3>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/static_array_inserting_elem_at_pos.cpp"> 4. 𝑰𝒏𝒔𝒆𝒓𝒕 𝑬𝒍𝒆𝒎𝒆𝒏𝒕 𝒂𝒕 𝒑𝒐𝒔𝒊𝒕𝒊𝒐𝒏 𝑰𝒏 𝒂𝒏 𝑨𝒓𝒓𝒂𝒚  </a> </h3>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/static_array_deleting_elem_at_pos.cpp"> 5. 𝑫𝒆𝒍𝒆𝒕𝒆 𝑬𝒍𝒆𝒎𝒆𝒏𝒕 𝒂𝒕 𝒑𝒐𝒔𝒊𝒕𝒊𝒐𝒏 𝑰𝒏 𝒂𝒏 𝑨𝒓𝒓𝒂𝒚  </a> </h3>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/static_two_dimensional_array.cpp"> 6.𝑻𝒘𝒐 − 𝑫𝒊𝒎𝒆𝒏𝒔𝒊𝒐𝒏𝒂𝒍 𝑨𝒓𝒓𝒂𝒚 </a> </h3>
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/static_three_dimensional_array.cpp"> 7.𝑻𝒉𝒓𝒆𝒆 − 𝑫𝒊𝒎𝒆𝒏𝒔𝒊𝒐𝒏𝒂𝒍 𝑨𝒓𝒓𝒂𝒚 </a> </h3>



</ul>

<h2><li> Dynamic Array Using Struct ,Pointers and Memory Allocation</li></h2>

<ul>
  
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_array_insert_and_traversal.cpp"> 1. 𝑰𝒏𝒊𝒕𝒊𝒂𝒍𝒊𝒛𝒂𝒕𝒊𝒐𝒏 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚 and 𝑻𝒓𝒂𝒗𝒆𝒓𝒔𝒂𝒍 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚𝒔 </a></h3>
  
<h3> 𝑪𝒂𝒏 𝒂𝒍𝒔𝒐 𝒃𝒆 𝒅𝒐𝒏𝒆 𝒕𝒉𝒓𝒐𝒖𝒈𝒉 𝒑𝒐𝒊𝒏𝒕𝒆𝒓: </h3>

<ul>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_array_insert_and_traversal1.cpp"> 1. 𝑰𝒏𝒊𝒕𝒊𝒂𝒍𝒊𝒛𝒂𝒕𝒊𝒐𝒏 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚 and 𝑻𝒓𝒂𝒗𝒆𝒓𝒔𝒂𝒍 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚𝒔(1) </a></h3>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_array_insert_and_traversal2.cpp"> 1. 𝑰𝒏𝒊𝒕𝒊𝒂𝒍𝒊𝒛𝒂𝒕𝒊𝒐𝒏 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚 and 𝑻𝒓𝒂𝒗𝒆𝒓𝒔𝒂𝒍 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚𝒔(2) </a></h3>



</ul>

<h3>𝑪𝒂𝒏 𝒂𝒍𝒔𝒐 𝒃𝒆 𝒅𝒐𝒏𝒆 𝒕𝒉𝒓𝒐𝒖𝒈𝒉 𝒑𝒐𝒊𝒏𝒕𝒆𝒓𝒔 𝒂𝒏𝒅 𝒕𝒚𝒑𝒆𝒅𝒆𝒇</h3>

<ul>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_array_insert_and_traversal3.cpp"> 1. 𝑰𝒏𝒊𝒕𝒊𝒂𝒍𝒊𝒛𝒂𝒕𝒊𝒐𝒏 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚 and 𝑻𝒓𝒂𝒗𝒆𝒓𝒔𝒂𝒍 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚𝒔(3) </a></h3>

</ul>
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_array_overriding_of_ith_elem.cpp"> 2. 𝑶𝒗𝒆𝒓𝒓𝒊𝒅𝒊𝒏𝒈 𝒊𝒕𝒉 𝒆𝒍𝒆𝒎𝒆𝒏𝒕 </a></h3>
  
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_Arrays_Inserting_Element_In_Array.cpp"> 3. 𝑰𝒏𝒔𝒆𝒓𝒕 𝑬𝒍𝒆𝒎𝒆𝒏𝒕 𝒊𝒏 𝑨𝒓𝒓𝒂𝒚 </a></h3>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_Arrays_Inserting_Element_At_A_Position_In_The_Array.cpp"> 4. 𝑰𝒏𝒔𝒆𝒓𝒕 𝑬𝒍𝒆𝒎𝒆𝒏𝒕 𝒂𝒕 𝒑𝒐𝒔𝒊𝒕𝒊𝒐𝒏 𝑰𝒏 𝒂𝒏 𝑨𝒓𝒓𝒂𝒚  </a> </h3>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_Arrays_Deleting_Element_At_A_Position_In_The_Array.cpp"> 5.𝑫𝒆𝒍𝒆𝒕𝒆 𝑬𝒍𝒆𝒎𝒆𝒏𝒕 𝒂𝒕 𝒑𝒐𝒔𝒊𝒕𝒊𝒐𝒏 𝑰𝒏 𝒂𝒏 𝑨𝒓𝒓𝒂𝒚 </a> </h3>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_Arrays_Two_Dimensional.cpp"> 6.𝑻𝒘𝒐 − 𝑫𝒊𝒎𝒆𝒏𝒔𝒊𝒐𝒏𝒂𝒍 𝑨𝒓𝒓𝒂𝒚 </a> </h3>
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_Arrays_Three_Dimensional.cpp"> 7.𝑻𝒉𝒓𝒆𝒆 − 𝑫𝒊𝒎𝒆𝒏𝒔𝒊𝒐𝒏𝒂𝒍 𝑨𝒓𝒓𝒂𝒚 </a> </h3>

<h3>𝑻𝒉𝒆 𝒇𝒓𝒆𝒆𝒊𝒏𝒈 𝒐𝒇 𝒎𝒆𝒎𝒐𝒓𝒚 𝒄𝒂𝒏 𝒂𝒍𝒔𝒐 𝒃𝒆 𝒅𝒐𝒏𝒆 𝒂𝒔:</h3>
 <ul>
   <h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_Arrays_Two_Dimensional1.cpp"> 1.𝑻𝒘𝒐 − 𝑫𝒊𝒎𝒆𝒏𝒔𝒊𝒐𝒏𝒂𝒍 𝑨𝒓𝒓𝒂𝒚 </a> </h3>
   <h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/struct_Arrays_Three_Dimensional1.cpp"> 2.𝑻𝒉𝒓𝒆𝒆 − 𝑫𝒊𝒎𝒆𝒏𝒔𝒊𝒐𝒏𝒂𝒍 𝑨𝒓𝒓𝒂𝒚 </a> </h3>
</ul>
<h3><ins>𝑵𝒐𝒕𝒆</ins>: 𝑰𝒏 𝒃𝒐𝒕𝒉 𝒕𝒉𝒆 𝒘𝒂𝒚𝒔 𝒎𝒆𝒎𝒐𝒓𝒚 𝒄𝒂𝒏 𝒃𝒆 𝒇𝒓𝒆𝒆𝒅, 𝒕𝒉𝒂𝒕 𝒇𝒓𝒆𝒆(𝒂𝒓𝒓->𝒂) 𝒐𝒓 𝒇𝒓𝒆𝒆𝒊𝒏𝒈 𝒆𝒂𝒄𝒉 𝒔𝒖𝒃 𝒂𝒓𝒓𝒂𝒚 𝒋𝒖𝒔𝒕 𝒍𝒊𝒌𝒆 𝒅𝒆𝒍𝒆𝒕𝒆 .𝑰𝒕 𝒎𝒂𝒊𝒏𝒍𝒚 𝒅𝒆𝒑𝒆𝒏𝒅𝒔 𝒐𝒏 𝒕𝒉𝒆 𝒇𝒂𝒄𝒕 𝒕𝒉𝒂𝒕 𝒉𝒐𝒘 𝒎𝒂𝒏𝒚 𝒑𝒐𝒊𝒏𝒕𝒆𝒓𝒔 𝒘𝒆 𝒂𝒓𝒆 𝒖𝒔𝒊𝒏𝒈.</h3>

</ul>


<h2><li> Dynamic Array Using Class </li></h2>

<ul>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/Arrays_init_trav_class_dyn.cpp"> 1. 𝑰𝒏𝒊𝒕𝒊𝒂𝒍𝒊𝒛𝒂𝒕𝒊𝒐𝒏 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚 and 𝑻𝒓𝒂𝒗𝒆𝒓𝒔𝒂𝒍 𝒐𝒇 𝑨𝒓𝒓𝒂𝒚𝒔 </a></h3>
  
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/Arrays_Overriding_Of_ith_Array.cpp"> 2. 𝑶𝒗𝒆𝒓𝒓𝒊𝒅𝒊𝒏𝒈 𝒊𝒕𝒉 𝒆𝒍𝒆𝒎𝒆𝒏𝒕 </a></h3>
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/Arrays_Overriding_Of_ith_Array.cpp"> 3.𝑰𝒏𝒔𝒆𝒓𝒕 𝑬𝒍𝒆𝒎𝒆𝒏𝒕 𝒊𝒏 𝑨𝒓𝒓𝒂𝒚 </a></h3>
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/Arrays_Insert_Element_At_Position_In_Array.cpp"> 4.𝑰𝒏𝒔𝒆𝒓𝒕 𝑬𝒍𝒆𝒎𝒆𝒏𝒕 𝒂𝒕 𝒑𝒐𝒔𝒊𝒕𝒊𝒐𝒏 𝑰𝒏 𝒂𝒏 𝑨𝒓𝒓𝒂𝒚 </a></h3>
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/Arrays_Delete_Element_At_Position_In_Array.cpp"> 5.𝑫𝒆𝒍𝒆𝒕𝒆 𝑬𝒍𝒆𝒎𝒆𝒏𝒕 𝒂𝒕 𝒑𝒐𝒔𝒊𝒕𝒊𝒐𝒏 𝑰𝒏 𝒂𝒏 𝑨𝒓𝒓𝒂𝒚 </a></h3>
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/Arrays_Two_Dimensional.cpp"> 6.𝑻𝒘𝒐 − 𝑫𝒊𝒎𝒆𝒏𝒔𝒊𝒐𝒏𝒂𝒍 𝑨𝒓𝒓𝒂𝒚</a></h3>
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/Arrays_Three_Dimensional.cpp"> 7.𝑻𝒉𝒓𝒆𝒆 − 𝑫𝒊𝒎𝒆𝒏𝒔𝒊𝒐𝒏𝒂𝒍 𝑨𝒓𝒓𝒂𝒚</a></h3>

<h3>𝑷𝒓𝒐𝒑𝒆𝒓 𝒅𝒆𝒍𝒆𝒕𝒊𝒐𝒏 𝒐𝒇 𝒂𝒓𝒓𝒂𝒚𝒔 𝒊𝒏𝒄𝒍𝒖𝒅𝒊𝒏𝒈 𝒓𝒐𝒘𝒔 , 𝒄𝒐𝒍𝒖𝒎𝒏𝒔 𝒂𝒏𝒅 𝒑𝒂𝒈𝒆𝒔 𝒊𝒏 𝑻𝒘𝒐 𝒂𝒏𝒅 𝑻𝒉𝒓𝒆𝒆 𝑫𝒊𝒎𝒆𝒏𝒔𝒊𝒐𝒏𝒂𝒍 𝑨𝒓𝒓𝒂𝒚𝒔 </h3>
<ul>
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/Arrays_Two_Dimensional_1.cpp"> 1.𝑻𝒘𝒐 − 𝑫𝒊𝒎𝒆𝒏𝒔𝒊𝒐𝒏𝒂𝒍 𝑨𝒓𝒓𝒂𝒚</a></h3>
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/Arrays_Three_Dimensional_1.cpp"> 2.𝑻𝒉𝒓𝒆𝒆 − 𝑫𝒊𝒎𝒆𝒏𝒔𝒊𝒐𝒏𝒂𝒍 𝑨𝒓𝒓𝒂𝒚</a></h3>

</ul>

<h3><ins>𝑵𝒐𝒕𝒆</ins>: 𝑰𝒏 𝒃𝒐𝒕𝒉 𝒕𝒉𝒆 𝒘𝒂𝒚𝒔 𝒊𝒕 𝒄𝒂𝒏 𝒃𝒆 𝒅𝒆𝒍𝒆𝒕𝒆𝒅 𝒆𝒊𝒕𝒉𝒆𝒓 𝒘𝒆 𝒖𝒔𝒆 ' 𝒅𝒆𝒍𝒆𝒕𝒆[] 𝒂𝒓𝒓 ' 𝒐𝒓 𝒅𝒆𝒍𝒆𝒕𝒆 𝒆𝒂𝒄𝒉 𝒔𝒖𝒃 𝒂𝒓𝒓𝒂𝒚𝒔 𝒇𝒐𝒓 𝒑𝒂𝒈𝒆𝒔/𝒃𝒍𝒐𝒄𝒌𝒔, 𝒓𝒐𝒘𝒔 𝒂𝒏𝒅 𝒄𝒐𝒍𝒖𝒎𝒏𝒔 . 𝑰𝒕 𝒎𝒂𝒊𝒏𝒍𝒚 𝒅𝒆𝒑𝒆𝒏𝒅𝒔 𝒐𝒏 𝒕𝒉𝒆 𝒇𝒂𝒄𝒕 𝒕𝒉𝒂𝒕 𝒉𝒐𝒘 𝒎𝒂𝒏𝒚 𝒑𝒐𝒊𝒏𝒕𝒆𝒓𝒔 𝒘𝒆 𝒂𝒓𝒆 𝒖𝒔𝒊𝒏𝒈.</h3>

</ul>
</ul>

<hr style="color:black;background-color:black;height:2px">
  
<h1> 2.Stack </h1>
  
 <ul>

<h2><li> 𝑺𝒕𝒂𝒄𝒌 𝒖𝒔𝒊𝒏𝒈 𝑺𝒕𝒂𝒕𝒊𝒄 𝑨𝒓𝒓𝒂𝒚 </li></h2>

<ul>
  
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/Stack_StaticArray.cpp"> 𝑺𝒕𝒂𝒄𝒌 𝒖𝒔𝒊𝒏𝒈 𝑺𝒕𝒂𝒕𝒊𝒄 𝑨𝒓𝒓𝒂𝒚</a></h3>
  
</ul>
   
<h2><li> 𝑺𝒕𝒂𝒄𝒌 𝒖𝒔𝒊𝒏𝒈 𝑫𝒚𝒏𝒂𝒎𝒊𝒄 𝑨𝒓𝒓𝒂𝒚 (𝑴𝒂𝒍𝒍𝒐𝒄)  </li></h2>
  
 <ul>
  
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/StackOperation_MallocStruct.cpp"> 𝑺𝒕𝒂𝒄𝒌 𝒖𝒔𝒊𝒏𝒈 𝑫𝒚𝒏𝒂𝒎𝒊𝒄 𝑨𝒓𝒓𝒂𝒚 (𝑴𝒂𝒍𝒍𝒐𝒄)</a></h3>
  
</ul>
   
<h2><li> 𝑺𝒕𝒂𝒄𝒌 𝒖𝒔𝒊𝒏𝒈 𝑫𝒚𝒏𝒂𝒎𝒊𝒄 𝑨𝒓𝒓𝒂𝒚 (𝑴𝒂𝒍𝒍𝒐𝒄) 𝒉𝒂𝒗𝒊𝒏𝒈 𝑨𝒎𝒐𝒓𝒕𝒊𝒛𝒆𝒅 𝑻𝒊𝒎𝒆 𝑪𝒐𝒎𝒑𝒍𝒆𝒙𝒊𝒕𝒚 </li></h2>
   
<ul>

<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/AmortizedStackOperation.cpp"> 𝑺𝒕𝒂𝒄𝒌 𝒖𝒔𝒊𝒏𝒈 𝑫𝒚𝒏𝒂𝒎𝒊𝒄 𝑨𝒓𝒓𝒂𝒚 (𝑴𝒂𝒍𝒍𝒐𝒄) 𝒉𝒂𝒗𝒊𝒏𝒈 𝑨𝒎𝒐𝒓𝒕𝒊𝒛𝒆𝒅 𝑻𝒊𝒎𝒆 𝑪𝒐𝒎𝒑𝒍𝒆𝒙𝒊𝒕𝒚 </a></h3>
 
</ul>
   
<h2><li> 𝑺𝒕𝒂𝒄𝒌 𝒖𝒔𝒊𝒏𝒈 𝑫𝒚𝒏𝒂𝒎𝒊𝒄 𝑨𝒓𝒓𝒂𝒚 (𝒖𝒔𝒊𝒏𝒈 𝒄𝒍𝒂𝒔𝒔 𝒂𝒏𝒅 𝒏𝒆𝒘 𝒐𝒑𝒆𝒓𝒂𝒕𝒐𝒓)  </li></h2>
   
<ul>
  
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/StackOperation_WithClass.cpp"> 𝑺𝒕𝒂𝒄𝒌 𝒖𝒔𝒊𝒏𝒈 𝑫𝒚𝒏𝒂𝒎𝒊𝒄 𝑨𝒓𝒓𝒂𝒚 (𝒖𝒔𝒊𝒏𝒈 𝒄𝒍𝒂𝒔𝒔 𝒂𝒏𝒅 𝒏𝒆𝒘 𝒐𝒑𝒆𝒓𝒂𝒕𝒐𝒓)  </a></h3> 
  
</ul>
   
<h2><li> 𝑺𝒕𝒂𝒄𝒌 𝒖𝒔𝒊𝒏𝒈 𝑫𝒚𝒏𝒂𝒎𝒊𝒄 𝑨𝒓𝒓𝒂𝒚 (𝒖𝒔𝒊𝒏𝒈 𝒄𝒍𝒂𝒔𝒔 𝒂𝒏𝒅 𝒏𝒆𝒘 𝒐𝒑𝒆𝒓𝒂𝒕𝒐𝒓) 𝒉𝒂𝒗𝒊𝒏𝒈 𝑨𝒎𝒐𝒓𝒕𝒊𝒛𝒆𝒅 𝑻𝒊𝒎𝒆 𝑪𝒐𝒎𝒑𝒍𝒆𝒙𝒊𝒕𝒚  </li></h2>
   
<ul>
  
<h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/AmortizedStackOperation_WithClass.cpp"> 𝑺𝒕𝒂𝒄𝒌 𝒖𝒔𝒊𝒏𝒈 𝑫𝒚𝒏𝒂𝒎𝒊𝒄 𝑨𝒓𝒓𝒂𝒚 (𝒖𝒔𝒊𝒏𝒈 𝒄𝒍𝒂𝒔𝒔 𝒂𝒏𝒅 𝒏𝒆𝒘 𝒐𝒑𝒆𝒓𝒂𝒕𝒐𝒓)  </a></h3> 
  
</ul>
   
</ul>
 
 <hr style="color:black;background-color:black;height:2px">

<h1></h1>
<h1>  𝟑.𝑷𝑶𝑷 𝑷𝑼𝑺𝑯 𝑰𝑵 𝑺𝑻𝑨𝑪𝑲 𝑨𝑻 𝑮𝑰𝑽𝑬𝑵 𝑷𝑶𝑺𝑻𝑰𝑶𝑵(𝑰𝒎𝒑𝒍𝒆𝒎𝒆𝒏𝒕𝒆𝒅 𝑻𝒉𝒓𝒐𝒖𝒈𝒉 𝑨𝒓𝒓𝒂𝒚)</h1>
  
<ul>
  
<h2><li> 𝑷𝑶𝑷 𝑷𝑼𝑺𝑯 𝑰𝑵 𝑺𝑻𝑨𝑪𝑲 𝑨𝑻 𝑮𝑰𝑽𝑬𝑵 𝑷𝑶𝑺𝑻𝑰𝑶𝑵 𝑼𝑺𝑰𝑵𝑮 𝑺𝑻𝑨𝑻𝑰𝑪 𝑨𝑹𝑹𝑨𝒀   </li></h2>  
  
<ul>
  
 <h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/PUSHPOPAtAPositioninStack%5BStatic%5D.cpp"> 𝑷𝑶𝑷 𝑷𝑼𝑺𝑯 𝑰𝑵 𝑺𝑻𝑨𝑪𝑲 𝑨𝑻 𝑮𝑰𝑽𝑬𝑵 𝑷𝑶𝑺𝑻𝑰𝑶𝑵 𝑼𝑺𝑰𝑵𝑮 𝑺𝑻𝑨𝑻𝑰𝑪 𝑨𝑹𝑹𝑨𝒀  </a></h3>  
  
</ul>
  
<h2><li> 𝑷𝑶𝑷 𝑷𝑼𝑺𝑯 𝑰𝑵 𝑺𝑻𝑨𝑪𝑲 𝑨𝑻 𝑮𝑰𝑽𝑬𝑵 𝑷𝑶𝑺𝑻𝑰𝑶𝑵 𝑼𝑺𝑰𝑵𝑮 𝑫𝒀𝑵𝑨𝑴𝑰𝑪 𝑨𝑹𝑹𝑨𝒀 (𝑼𝑺𝑰𝑵𝑮 𝑴𝑨𝑳𝑳𝑶𝑪)   </li></h2>  
  
<ul>
  
  <h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/PUSHPOPAtAPositioninStack.cpp"> 𝑷𝑶𝑷 𝑷𝑼𝑺𝑯 𝑰𝑵 𝑺𝑻𝑨𝑪𝑲 𝑨𝑻 𝑮𝑰𝑽𝑬𝑵 𝑷𝑶𝑺𝑻𝑰𝑶𝑵 𝑼𝑺𝑰𝑵𝑮 𝑫𝒀𝑵𝑨𝑴𝑰𝑪 𝑨𝑹𝑹𝑨𝒀 (𝑼𝑺𝑰𝑵𝑮 𝑴𝑨𝑳𝑳𝑶𝑪)   </a></h3> 
  
</ul>
  
<h2><li> 𝑷𝑶𝑷 𝑷𝑼𝑺𝑯 𝑰𝑵 𝑺𝑻𝑨𝑪𝑲 𝑨𝑻 𝑮𝑰𝑽𝑬𝑵 𝑷𝑶𝑺𝑻𝑰𝑶𝑵 𝑼𝑺𝑰𝑵𝑮 𝑫𝒀𝑵𝑨𝑴𝑰𝑪 𝑨𝑹𝑹𝑨𝒀 (𝑼𝑺𝑰𝑵𝑮 𝑪𝑳𝑨𝑺𝑺)   </li></h2>  
  
<ul>
  
  <h3> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/PUSHPOPAtAPositioninStack%5BClass%5D.cpp"> 𝑷𝑶𝑷 𝑷𝑼𝑺𝑯 𝑰𝑵 𝑺𝑻𝑨𝑪𝑲 𝑨𝑻 𝑮𝑰𝑽𝑬𝑵 𝑷𝑶𝑺𝑻𝑰𝑶𝑵 𝑼𝑺𝑰𝑵𝑮 𝑫𝒀𝑵𝑨𝑴𝑰𝑪 𝑨𝑹𝑹𝑨𝒀 (𝑼𝑺𝑰𝑵𝑮 𝑪𝑳𝑨𝑺𝑺)  </a></h3> 
  
</ul>
  
</ul>

 <hr style="color:black;background-color:black;height:2px">
  

  <h1></h1>
<h1>  𝟒.𝑰𝒏𝒇𝒊𝒙 𝒕𝒐 𝑷𝒐𝒔𝒕𝒇𝒊𝒙 𝒄𝒐𝒏𝒗𝒆𝒓𝒔𝒊𝒐𝒏</h1>
  
<ul>
   
<h2><li> 𝑷𝒓𝒊𝒐𝒓𝒊𝒕𝒚 𝑪𝒉𝒆𝒄𝒌𝒆𝒓  </li></h2>  
   
<ul>
   
<h3><li><a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/proritychecker.cpp"> 𝑷𝒓𝒊𝒐𝒓𝒊𝒕𝒚 𝑪𝒉𝒆𝒄𝒌𝒆𝒓 (𝒖𝒔𝒊𝒏𝒈 𝑰𝒇-𝑬𝒍𝒔𝒆 𝒔𝒕𝒂𝒕𝒆𝒎𝒆𝒏𝒕)  </a></li></h3>  
 
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/proritycheckerthroughSwitch.cpp"> 𝑷𝒓𝒊𝒐𝒓𝒊𝒕𝒚 𝑪𝒉𝒆𝒄𝒌𝒆𝒓 (𝒖𝒔𝒊𝒏𝒈 𝑺𝒘𝒊𝒕𝒄𝒉-𝑪𝒂𝒔𝒆 𝒔𝒕𝒂𝒕𝒆𝒎𝒆𝒏𝒕)  </a></li></h3>
   
</ul>
  
<h2><li>𝑰𝒏𝒇𝒊𝒙 𝒕𝒐 𝑷𝒐𝒔𝒕𝒇𝒊𝒙 𝒄𝒐𝒏𝒗𝒆𝒓𝒔𝒊𝒐𝒏  </li></h2>   
  
  <ul>
   
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/InfixToPostfix(static).cpp"> 𝑰𝒏𝒇𝒊𝒙 𝒕𝒐 𝑷𝒐𝒔𝒕𝒇𝒊𝒙 𝒄𝒐𝒏𝒗𝒆𝒓𝒔𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑺𝒕𝒂𝒕𝒊𝒄 𝑨𝒓𝒓𝒂𝒚)  </a></li></h3>
 
 <ul>
   
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/InfixToPostfix(static)type2.cpp"> 𝑰𝒏𝒇𝒊𝒙 𝒕𝒐 𝑷𝒐𝒔𝒕𝒇𝒊𝒙 𝒄𝒐𝒏𝒗𝒆𝒓𝒔𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑺𝒕𝒂𝒕𝒊𝒄 𝑨𝒓𝒓𝒂𝒚-𝑻𝒚𝒑𝒆 𝟐)  </a></li></h3>  
   
<h3><ins>𝑵𝒐𝒕𝒆</ins>: 𝒊𝒔𝒂𝒍𝒏𝒖𝒎() 𝒊𝒔 𝒂 𝒇𝒖𝒏𝒄𝒕𝒊𝒐𝒏 𝒐𝒇
𝒄𝒕𝒚𝒑𝒆. 𝒉 𝒉𝒆𝒂𝒅𝒆𝒓 𝒇𝒊𝒍𝒆 𝒇𝒐𝒓 𝑪 𝒂𝒍𝒔𝒐 𝒑𝒓𝒆𝒔𝒆𝒏𝒕 𝒊𝒏
𝒄𝒄𝒕𝒚𝒑𝒆 𝒇𝒊𝒍𝒆 𝒇𝒐𝒓 𝑪 + +, 𝒄𝒉𝒆𝒄𝒌𝒔
𝒂𝒍𝒑𝒉𝒂𝒃𝒆𝒕𝒔(𝒂 − 𝒛, 𝑨 − 𝒁)𝒂𝒏𝒅
𝒏𝒖𝒎𝒃𝒆𝒓𝒔(𝟎 − 𝟗) 𝒕𝒐𝒈𝒆𝒕𝒉𝒆𝒓 𝒌𝒏𝒐𝒘𝒏 𝒂𝒔 "𝑨𝒍𝒑𝒉𝒂-𝑵𝒖𝒎𝒆𝒓𝒊𝒄" 𝒊𝒔 𝒖𝒔𝒆𝒅 𝒉𝒆𝒓𝒆.</h3>   
   
 </ul>   
    
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/InfixToPostfix(Malloc).cpp"> 𝑰𝒏𝒇𝒊𝒙 𝒕𝒐 𝑷𝒐𝒔𝒕𝒇𝒊𝒙 𝒄𝒐𝒏𝒗𝒆𝒓𝒔𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑴𝒂𝒍𝒍𝒐𝒄(𝑫𝒚𝒏𝒂𝒎𝒊𝒄))  </a></li></h3>
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/InfixToPostfix(Class).cpp"> 𝑰𝒏𝒇𝒊𝒙 𝒕𝒐 𝑷𝒐𝒔𝒕𝒇𝒊𝒙 𝒄𝒐𝒏𝒗𝒆𝒓𝒔𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑪𝒍𝒂𝒔𝒔(𝑫𝒚𝒏𝒂𝒎𝒊𝒄))  </a></li></h3>
   
</ul>
  
  
<h2><li> 𝑷𝒐𝒔𝒕𝒇𝒊𝒙 𝑬𝒗𝒂𝒍𝒖𝒂𝒕𝒊𝒐𝒏  </li></h2>   
  
 <ul>
   
 <h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/PostfixEvaluation(Static).cpp "> 𝑷𝒐𝒔𝒕𝒇𝒊𝒙 𝑬𝒗𝒂𝒍𝒖𝒂𝒕𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑺𝒕𝒂𝒕𝒊𝒄 𝑨𝒓𝒓𝒂𝒚)  </a></li></h3>
   
 <ul>
 
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/PostfixEvaluation(StaticType2).cpp ">  𝑷𝒐𝒔𝒕𝒇𝒊𝒙 𝑬𝒗𝒂𝒍𝒖𝒂𝒕𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑺𝒕𝒂𝒕𝒊𝒄 𝑨𝒓𝒓𝒂𝒚-𝑻𝒚𝒑𝒆 𝟐)</a></li></h3> 
   
<h3><ins>𝑵𝒐𝒕𝒆</ins>: 𝒊𝒔𝑫𝒊𝒈𝒊𝒕() 𝒊𝒔 𝒂 𝒇𝒖𝒏𝒄𝒕𝒊𝒐𝒏 𝒐𝒇
𝒄𝒕𝒚𝒑𝒆. 𝒉 𝒉𝒆𝒂𝒅𝒆𝒓 𝒇𝒊𝒍𝒆 𝒇𝒐𝒓 𝑪 𝒂𝒍𝒔𝒐 𝒑𝒓𝒆𝒔𝒆𝒏𝒕 𝒊𝒏
𝒄𝒄𝒕𝒚𝒑𝒆 𝒇𝒊𝒍𝒆 𝒇𝒐𝒓 𝑪 + +, 𝒇𝒖𝒏𝒄𝒕𝒊𝒐𝒏 𝒄𝒉𝒆𝒄𝒌𝒔 𝒘𝒉𝒆𝒕𝒉𝒆𝒓 𝒕𝒉𝒆 𝒑𝒂𝒔𝒔𝒆𝒅 𝒄𝒉𝒂𝒓𝒂𝒄𝒕𝒆𝒓 𝒊𝒔 𝒂 𝒅𝒊𝒈𝒊𝒕 𝒐𝒓 𝒏𝒐𝒕.</h3>
  
<h3><ins>𝑵𝒐𝒕𝒆</ins>:  𝑺𝒊𝒎𝒊𝒍𝒂𝒓𝒍𝒚, 𝒎𝒂𝒕𝒉.𝒉 𝒉𝒆𝒂𝒅𝒆𝒓 𝒇𝒊𝒍𝒆 𝒖𝒔𝒆𝒅 𝒊𝒏 𝑪 𝒘𝒉𝒊𝒍𝒆 𝒄𝒎𝒂𝒕𝒉 𝒇𝒊𝒍𝒆 𝒖𝒔𝒆𝒅 𝒇𝒐𝒓 𝒄++.</h3>    
   
 </ul>  
   
   
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/PostfixEvaluation(Dynamic%20Using%20Malloc).cpp">  𝑷𝒐𝒔𝒕𝒇𝒊𝒙 𝑬𝒗𝒂𝒍𝒖𝒂𝒕𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑴𝒂𝒍𝒍𝒐𝒄(𝑫𝒚𝒏𝒂𝒎𝒊𝒄))</a></li></h3>  
   
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/PostfixEvaluation(WithClass).cpp">  𝑷𝒐𝒔𝒕𝒇𝒊𝒙 𝑬𝒗𝒂𝒍𝒖𝒂𝒕𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑪𝒍𝒂𝒔𝒔(𝑫𝒚𝒏𝒂𝒎𝒊𝒄))</a></li></h3>    
   

   
 </ul>  
  
  
<h2><li> 𝑰𝒏𝒇𝒊𝒙 𝒕𝒐 𝑷𝒓𝒆𝒇𝒊𝒙 𝑪𝒐𝒏𝒗𝒆𝒓𝒔𝒊𝒐𝒏  </li></h2>   
  
  <ul>
   
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/InfixToPrefix(static).cpp"> 𝑰𝒏𝒇𝒊𝒙 𝒕𝒐 𝑷𝒓𝒆𝒇𝒊𝒙 𝑪𝒐𝒏𝒗𝒆𝒓𝒔𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑺𝒕𝒂𝒕𝒊𝒄 𝑨𝒓𝒓𝒂𝒚)  </a></li></h3>
 
 <ul>
   
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/InfixToPrefix(static)type2.cpp">  𝑰𝒏𝒇𝒊𝒙 𝒕𝒐 𝑷𝒓𝒆𝒇𝒊𝒙 𝑪𝒐𝒏𝒗𝒆𝒓𝒔𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑺𝒕𝒂𝒕𝒊𝒄 𝑨𝒓𝒓𝒂𝒚-𝑻𝒚𝒑𝒆 𝟐)  </a></li></h3>  
   
<h3><ins>𝑵𝒐𝒕𝒆</ins>: 𝒊𝒔𝒂𝒍𝒏𝒖𝒎(),𝒊𝒔𝑫𝒊𝒈𝒊𝒕() 𝒇𝒖𝒏𝒄𝒕𝒊𝒐𝒏 𝒖𝒔𝒆𝒅 𝒂𝒍𝒐𝒏𝒈 𝒘𝒊𝒕𝒉 𝒔𝒕𝒓𝒊𝒏𝒈 , 𝒘𝒉𝒊𝒄𝒉 𝒓𝒆𝒑𝒓𝒆𝒔𝒆𝒏𝒕𝒔 𝒂𝒏 𝒂𝒓𝒓𝒂𝒚 𝒐𝒇 𝒄𝒉𝒂𝒓𝒂𝒄𝒕𝒆𝒓𝒔. 𝑨𝒏𝒅 𝒂𝒏𝒐𝒕𝒉𝒆𝒓 𝒇𝒖𝒏𝒄𝒕𝒊𝒐𝒏 𝒐𝒇 𝒄𝒔𝒕𝒓𝒊𝒏𝒈 𝒇𝒊𝒍𝒆 𝒕𝒚𝒑𝒆 𝒐𝒇 𝒄++ 𝒊.𝒆. 𝒑𝒖𝒔𝒉_𝒃𝒂𝒄𝒌() 𝒇𝒖𝒏𝒄𝒕𝒊𝒐𝒏 , 𝒘𝒉𝒊𝒄𝒉 𝒉𝒆𝒍𝒑𝒔 𝒕𝒐 𝒂𝒑𝒑𝒆𝒏𝒅 𝒔𝒊𝒏𝒈𝒍𝒆 𝒄𝒉𝒂𝒓𝒂𝒄𝒕𝒆𝒓 𝒂𝒕 𝒂 𝒕𝒊𝒎𝒆 𝒘𝒊𝒕𝒉 𝒕𝒊𝒎𝒆 𝒄𝒐𝒎𝒑𝒍𝒆𝒙𝒊𝒕𝒚 𝑶(1) 𝒊.𝒆. 𝒂𝒕 𝒂 𝒄𝒐𝒏𝒔𝒕𝒂𝒏𝒕 𝒕𝒊𝒎𝒆 .</h3>   
   
 </ul>   
    
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/InfixToPrefix(With%20Malloc).cpp"> 𝑰𝒏𝒇𝒊𝒙 𝒕𝒐 𝑷𝒓𝒆𝒇𝒊𝒙 𝒄𝒐𝒏𝒗𝒆𝒓𝒔𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑴𝒂𝒍𝒍𝒐𝒄(𝑫𝒚𝒏𝒂𝒎𝒊𝒄))  </a></li></h3>
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/InfixToPrefix(With%20Class).cpp"> 𝑰𝒏𝒇𝒊𝒙 𝒕𝒐 𝑷𝒓𝒆𝒇𝒊𝒙 𝒄𝒐𝒏𝒗𝒆𝒓𝒔𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑪𝒍𝒂𝒔𝒔(𝑫𝒚𝒏𝒂𝒎𝒊𝒄))  </a></li></h3>
   
</ul>  
  
  
  
<h2><li> 𝑷𝒓𝒆𝒇𝒊𝒙 𝑬𝒗𝒂𝒍𝒖𝒂𝒕𝒊𝒐𝒏  </li></h2>   
  
 <ul>
   
 <h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/PrefixEvaluation(with%20Static).cpp "> 𝑷𝒓𝒆𝒇𝒊𝒙 𝑬𝒗𝒂𝒍𝒖𝒂𝒕𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑺𝒕𝒂𝒕𝒊𝒄 𝑨𝒓𝒓𝒂𝒚)  </a></li></h3>
   
 <ul>
 
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/PrefixEvaluation(with%20StaticType2).cpp">  𝑷𝒓𝒆𝒇𝒊𝒙 𝑬𝒗𝒂𝒍𝒖𝒂𝒕𝒊𝒐𝒏(𝒖𝒔𝒊𝒏𝒈 𝑺𝒕𝒂𝒕𝒊𝒄 𝑨𝒓𝒓𝒂𝒚-𝑻𝒚𝒑𝒆 𝟐)</a></li></h3> 
   
 
   
 </ul>  
   
   
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/PrefixEvaluation(Dynamic%20Using%20Malloc).cpp">  𝑷𝒓𝒆𝒇𝒊𝒙 𝑬𝒗𝒂𝒍𝒖𝒂𝒕𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑴𝒂𝒍𝒍𝒐𝒄(𝑫𝒚𝒏𝒂𝒎𝒊𝒄))</a></li></h3>  
   
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/PrefixEvaluation(with%20Class).cpp">  𝑷𝒓𝒆𝒇𝒊𝒙 𝑬𝒗𝒂𝒍𝒖𝒂𝒕𝒊𝒐𝒏 (𝒖𝒔𝒊𝒏𝒈 𝑪𝒍𝒂𝒔𝒔(𝑫𝒚𝒏𝒂𝒎𝒊𝒄))</a></li></h3>    
   

   
 </ul>  
 
  
</ul>
  
  <hr style="color:black;background-color:black;height:2px">

<ul>

<h2><li>𝑹𝒆𝒄𝒖𝒓𝒔𝒊𝒐𝒏 </li></h2>   

<ul>
<h2><li>𝑻𝒚𝒑𝒆𝒔 𝒐𝒇 𝑹𝒆𝒄𝒖𝒓𝒔𝒊𝒐𝒏 </li></h2>   


<ul>
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/TypesOfRec_HeadRecursion.cpp"> 𝑨.𝑯𝒆𝒂𝒅 𝑹𝒆𝒄𝒖𝒓𝒔𝒊𝒐𝒏</a></li></h3> 
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/TypesOfRec_TailRecursion.cpp">𝑩. 𝑻𝒂𝒊𝒍 𝑹𝒆𝒄𝒖𝒓𝒔𝒊𝒐𝒏</a></li></h3>  
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/TypesOfRec_TreeRecursion.cpp"> 𝑪.𝑻𝒓𝒆𝒆 𝑹𝒆𝒄𝒖𝒓𝒔𝒊𝒐𝒏</a></li></h3>  
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/TypesOfRec_nestedRecursion.cpp">𝑫. 𝑵𝒆𝒔𝒕𝒆𝒅 𝑹𝒆𝒄𝒖𝒓𝒔𝒊𝒐𝒏</a></li></h3> 
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/TypesOfRec_implicitRecursion.cpp"> 𝑬.𝑰𝒎𝒑𝒍𝒊𝒄𝒊𝒕 𝑹𝒆𝒄𝒖𝒓𝒔𝒊𝒐𝒏</a></li></h3> 

<ul>
  
<h3><li> <a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/TypesOfRec_IndirectRecursion.cpp"> 𝑬.𝒂.𝑰𝒏𝒅𝒊𝒓𝒆𝒄𝒕 𝑹𝒆𝒄𝒖𝒓𝒔𝒊𝒐𝒏</a></li></h3>

</ul>

</ul>

<h2><li>𝑹𝒆𝒄𝒖𝒓𝒔𝒊𝒐𝒏 𝑩𝒂𝒔𝒆𝒅 𝒐𝒏 𝑳𝒊𝒏𝒆𝒂𝒓 𝑹𝒆𝒄𝒖𝒓𝒓𝒆𝒏𝒄𝒆 𝑬𝒒𝒖𝒂𝒕𝒊𝒐𝒏𝒔 </li></h2> 

<ul>
  
<h3><a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/recursion_handshake_problem.cpp">𝑨. 𝑯𝒂𝒏𝒅 𝑺𝒉𝒂𝒌𝒆 𝑷𝒓𝒐𝒃𝒍𝒆𝒎</a></h3>

<h3><a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/recursion_fibonacci_series.cpp">𝑩.𝑭𝒊𝒃𝒐𝒏𝒂𝒄𝒄𝒊 𝑺𝒆𝒓𝒊𝒆𝒔</a></h3>

<h3><a href="https://github.com/AvinandanBose/CPLUSPLUS_DataStructure/blob/main/factorial.cpp">𝑪.𝑭𝒂𝒄𝒕𝒐𝒓𝒊𝒂𝒍 </a></h3>

</ul>

</ul>

</ul>  
