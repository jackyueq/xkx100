// Room: /d/wuxi/wuguan.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���߽��������̾ͱ��������������ľ��������ס�ˣ����ſ�����
��һ����ˣ���һ���ڵ��ӻƱߵĴ��죬����һ�����ġ��䡱�֡���
Բ������֮�ڵĺ�����Ӷ�������ѧ�գ���������䳡�Ϻ������󡣹�
���ؽ�ͷ�������ɣ��洫��ʮ�˰����գ�Ҳ����һ���ĺ����ˡ�
LONG );
	set("exits", ([
		"west" : __DIR__"northroad2",
		"east" : __DIR__"wuchang",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", 380);
	set("coor/y", -770);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}