// Room: /d/wudujiao/caoping.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
ɽ����һ��Ƭ�����أ�����������Ʈ�ż�����ƣ���������
���͵Ĳݵأ�ǳǳ�ĸպÿ��Ըǹ�����,ɢ����һ�����˵ķ���
�������ֱ��������������ǰ���м����ª�����ᡣ
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"zhushe",
                "northdown" : __DIR__"shanlu3",
        ]));

	set("coor/x", -44000);
	set("coor/y", -78130);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}