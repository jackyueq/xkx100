// Room: /d/qilian/qitianfeng.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������ɽ����һ�߷壬ֱ�����ƣ���·��Ѱ��ֻ��ɽǰ����һ���
ʯ (stone)������ɽ����������ʱ�к��������˳����ɽ���е������
����ɽ֮̽����δ������
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"eastdown" : __DIR__"zibaipo",
		"westdown" : __DIR__"tanglangling",
	]));
	set("objects", ([
		"/d/xingxiu/npc/trader" : 1,
	]));
	set("coor/x", -15000);
	set("coor/y", 3000);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}