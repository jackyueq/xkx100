// wg_houyuan3.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����Ǻ�Ժ���ˣ����ܶ��ǲ˵أ������Ǹ�Сɽ�£������涼����
���Χ��Ĳ˵أ����Ÿ����Ĳˣ���ʺ����ã�ҡҡ��׹����������û
ʲô�˴���
LONG);
	set("exits", ([
		"north" : __DIR__"wg_caidi2",
		"south" : __DIR__"wg_caidi1",
		"west" : __DIR__"wg_houyuan2",
	]));
	set("objects", ([	    
		__DIR__"npc/wg_ryjdizi" : 1,
		__DIR__"npc/wg_baituodizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 81);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

