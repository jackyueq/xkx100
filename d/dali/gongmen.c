//Room: /d/dali/road1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short", "����");
	set("long",@LONG
�����Ǵ���ʹ��Ĺ��ţ��ſڷ��������ߴ�ʯʨ������ʵ�û��
һ����ӣ���������ֹ���ǽ���ʹ������������֣������ͽ���ʹ�
�ˡ�
LONG);
	set("outdoors", "daligong");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"qiandian",
	    "south"  : __DIR__"yujie",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40010);
	set("coor/y", -70990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}