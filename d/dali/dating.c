//Room: /d/dali/dating.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�廪¥����");
	set("long",@LONG
�������廪¥��ǰ�������쳣������������һ�������ȫ����
ʯ�̵أ��ڰ���䣬����������ɶ�����ǧ�ˡ�ʱʱ�ɼ�����������
����ʳ�������ߡ�
LONG);
	set("objects", ([
	   __DIR__"npc/shizhe": 3,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"   : __DIR__"louti",
	    "out"     : __DIR__"gudao",
	]));
	set("coor/x", -50000);
	set("coor/y", -75010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}