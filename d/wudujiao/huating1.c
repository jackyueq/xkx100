// Room: /d/wudujiao/huating1.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�����ű��µĻ��������ܹ��ű�ɴ����ʣ��ݽ���¯��Ʈ��һ
���������������һ���ۺ���ȹ����Ů�����ڴ��߷����������Ų��������
����һ������ü΢΢һ򭣬�ƺ���̫���ˡ�
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"huating2",
                "north" : __DIR__"huating3",
                "west"  : __DIR__"huayuan1",
        ]));
        set("objects", ([
                CLASS_D("wudujiao")+"/hetieshou": 1,
        ]));

	set("coor/x", -44890);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
}
