// Room: /d/wudujiao/shanlu2.c

inherit ROOM;

void create()
{
        set("short", "��ɽС·");
        set("long", @LONG
����һ����ɽ��С·����������ʯ���ɵ�̨�ף�ʪ�����ĳ�
������̦������ȫ��ï�ܵ����֡�Զ������һ�������ɽ������
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "southup"   : __DIR__"shanlu3",
                "northdown" : __DIR__"xiaolu",
        ]));

	set("coor/x", -44000);
	set("coor/y", -78110);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}