// Room: /d/wudujiao/bianzhai1.c

inherit ROOM;

void create()
{
        set("short", "��կ����");
        set("long", @LONG
���������置�ؽ磬ֻ����ɽ��ˮ�㣬�羰����ԭ����ͬ��
����·�ϣ���ʱ������������Ů��·����Ұ���ظ����裬�پ���
���泩����Ը���ϴ��硣������������ĺ�ɭ���ˡ�
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);

        set("exits", ([
                "south" : __DIR__"milin8",
                "west" : __DIR__"bianzhai2",
                "southwest" : __DIR__"bianzhai3",
        ]));

	set("coor/x", -46000);
	set("coor/y", -81000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}