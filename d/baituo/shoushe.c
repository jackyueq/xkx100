// Room: /d/baituo/shoushe.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�����ǰ���ɽׯ�����ᡣ����ɽԦ��������֪��������Ҳ�����˸�
�����ޣ��Թ���ɽ�İ��յ���ʹ�á����������޳���˻������Զ������
����������ҹ��������������˺���ѷεĲ��ҡ�
LONG );
	set("exits",([
		"east"  : __DIR__"tuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/fox" :1,
		__DIR__"npc/wolf" :1,
		__DIR__"npc/tiger" :1,
		__DIR__"npc/lion" :1,
	]));
	set("coor/x", -50010);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
