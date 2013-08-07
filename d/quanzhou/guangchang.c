// Room: /d/quanzhou/guangchang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "���Ĺ㳡");
	set("long", @LONG
����Ȫ�ݵ����ĵش�������Ũ�������뻮һ���㳡����ɽ�˺���Ħ
����࣬������������Ⱥ��ʱ���ɼ���ͬ��ɫ�ĺ��ˡ�Ȫ�������ֲ��
ͩ������������ͩ�ǡ����ǡ�����˿��֮·������㡣������Ƶ����
�̼֡�ʹ�ں��ڽ���ͽԶ�����������˵أ����в����˾Ͷ����ڴˡ�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"eastroad1",
		"west"  : __DIR__"westroad1",
		"south" : __DIR__"southroad1",
		"north" : __DIR__"northroad1",
	]));
	set("objects", ([
		__DIR__"npc/huren" : 1,
		__DIR__"npc/xiaofan" : 1,
		"/d/city/npc/liumangtou" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
