// Room: /d/lingxiao/huajing.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG 
����һ�������˸�ɫ÷���Ļ�������С�����ߣ�÷��Ʈ�㣬÷����
������Ȼ���ͼ���÷֦���ѣ�÷����᫣�����Ʈ�ݣ������֮��÷��֦
���Կݲг�׾Ϊ��÷��÷���Է���Ũ��Ϊ�У��˴�֮������ν���ӡ�
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"qianyuan",
		"up"   : __DIR__"feihua",  
	]));
	set("objects", ([
	       __DIR__"npc/xuehe" : 1,
	       __DIR__"obj/mei" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8880);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

