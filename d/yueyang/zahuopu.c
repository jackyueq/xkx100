// Room: /d/yueyang/zahuopu.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��̣������������õ����ӣ����ﲻ�٣��ѵ�Ҳ
�ң��ϰ���Ȼûʱ���������СС���档�ⲻ����һ����������ӭ����
����
    ǽ������һ������(zhaopai)��
LONG );
	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"west" : __DIR__"beijie",
	]));
	set("objects", ([
		__DIR__"npc/laoban": 1,
	]));
	set("coor/x", -1400);
	set("coor/y", -2260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
