// Room: /d/village/shop.c

inherit ROOM;

void create()
{
        set("short", "�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��꣬��ӪЩ�͡��Ρ������׼����ðٻ���������
���˶����Ǻ�������������Ʒ��������ٷ���������Ʒ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"eroad3",
        ]));
//        set("no_clean_up", 0);
        set("objects", ([
            __DIR__"npc/xiejian": 1
        ]) );

	set("coor/x", -960);
	set("coor/y", 280);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
 