//Room: /d/dali/jianchuankou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����ɽ��");
	set("long",@LONG
�����ǲ�ɽ��´��һ�����ĳ��򡣴˵�����ɽ�ڣ����߳�ɽ����
������������·���У�Ψ�д���������ɽ������Ǵ������������
����Ҫ�壬������ڴ����е�¥����������פ�����йٱ������վ��
Ѳ�ߣ��̲�������ˡ�
LONG);
	set("objects", ([
	   __DIR__"npc/jiang": 1,
	   __DIR__"npc/bing": 3,
	]));
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "northup"    : __DIR__"shanlu1",
	    "south"      : __DIR__"jianchuan",
	]));
	set("coor/x", -44000);
	set("coor/y", -54000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}