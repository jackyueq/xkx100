// Room: /d/village/smithy1.c

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����һ�����Ǽ�ª�������̣����������Ǹ������裬����ú��������
ǽ�Ϲ��ż�����ͷ�����ӵĽ�������ż����Ƴ�ͷ����������ǽ���ż���
�³�¯��������������һ��С�ţ����Ϲ������Ʋ�����
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"smithy2",
            "north" : __DIR__"eroad3",
        ]));
//        set("no_clean_up", 0);
        set("objects", ([
             __DIR__"npc/smith": 1
        ]) );

	set("coor/x", -960);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
 