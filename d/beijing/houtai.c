inherit ROOM;

void create()
{
	set("short", "ϷԺ��̨");
	set("long", @LONG
������ϷԺ��̨������Ϸ�����ڻ�ױ���ӱ��߿�����̨��
LONG );
	set("exits", ([
  		"west"    : __DIR__"xiyuan",
  		"northup" : __DIR__"stage",
	]));
        set("objects", ([
                __DIR__"npc/xizi" : 2,
        ]));
	set("coor/x", -200);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
