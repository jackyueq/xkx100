inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
������������֮һ�������Ƴ��������Զ����Ȼ�����Ѿ�ʯ���߲���
������Ȼ����ͦ�Σ�ٲȻ�������°���������������
LONG );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "east" : __DIR__"talin",
        ]));
	set("objects",([
                "/d/wudang/npc/guest" : 2,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -37010);
	set("coor/y", -57010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}