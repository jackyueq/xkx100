// Room: /d/lingxiao/walle3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "��ͷ");
	set("long", @LONG
Զɽ���죬����������Է����£�ֻ����ɫ��ѩ����������֮����
Ω����ѩ���࣬����߮�ˡ���Į�Բԣ�Զ��һӥ���裬���ֱ�ɾ�����
������ֱ����£�������죬˲�����٣�ֻ�а���ǧ�أ����������³�
������Ʈ����
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"west" : __DIR__"walle2",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -30970);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

