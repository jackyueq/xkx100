// Last Modified by Sir on May. 22 2001
//Room: byawest.c ����������

inherit ROOM;
void create()
{
	set("short","����������");
	set("long",@LONG
�����Ǻ�ɽ���������ȡ���������ͨ��ի�ã�����ͨ����Ϣ�ҡ�
LONG);
	set("outdoors", "hengshan");
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"baiyunan", 
		"west" : __DIR__"xiuxishi", 
		"north" : __DIR__"zhaitang", 
	]));
	set("objects", ([
		__DIR__"npc/zheng" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 30);
	set("coor/y", 3210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
