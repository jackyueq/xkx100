//Room: /d/dali/shirenfang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ʯ�˷�");
	set("long",@LONG
����������������ͥԺ�϶˵�ʯ�˷������а���һЩ�����ز���
ʯ�ˣ������������������ıڿ���С���ڣ���̨�Ϸ��ż���С�軨��
��������Ҳ����ס������ʱ��������ɫ�ͷ��㡣
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "north" : __DIR__"tingyuan",
	]));
	set("objects",([ /* sizeof() == 1 */
	    __DIR__"npc/shi-ren" : 5,
	]));
	set("coor/x", -38980);
	set("coor/y", -70010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}