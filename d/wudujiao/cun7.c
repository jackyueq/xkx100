// Room: /d/wudujiao/cun7.c

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
����С���ʯ��·�ϣ����Զ�������ʯ���ɵķ��ݡ�������һ��ѧ�ã�
���洫�����ʵĶ�������
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "northwest" : __DIR__"cun5",
                "southeast" : __DIR__"cun8",
                "southwest" : __DIR__"cun6",
                "east" : __DIR__"minju7",
        ]));

	set("coor/x", -44940);
	set("coor/y", -81010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}