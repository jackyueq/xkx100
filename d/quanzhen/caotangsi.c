// caotangsi.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ��λ�����ɽ��´��С�¡���Ժ�е�һ�ڹž�����Ϊ����
������Ϊÿ���峿������һ�ɾ޴�������Ծ����������𣬲�����
�����ˣ�����Ϊ��һ�۴��澰����������һ����᫵�ɽ����������һ
����ɭɭ��С����
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southup"     : __DIR__"shanlu13",
//              "north"       : __DIR__"",
        ]));
        set("no_clean_up", 0);

	set("coor/x", -3180);
	set("coor/y", 120);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
