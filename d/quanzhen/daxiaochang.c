// daxiaochang.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��У��");
        set("long", @LONG
����һ��λ�����ɽɽ����Բƺ������Ⱥɽ������ɽ������һ��
��ء�ÿ�����£�ȫ���ɱ�춴˵ؾ��д�У���Կ������µ�������һ
���Ľ�����������һ����᫵�ɽ����������һ��ͨ���嶥��ɽ·��
�����б�����������ֻ��Զ��ʮ�Ŵ������������������ɢ��ɽ�䡣
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"     : __DIR__"shijie1",
                "westup"      : __DIR__"shanlu13",
                "southdown"   : __DIR__"shanlu12",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/pi": 1,
        ]));

	set("coor/x", -3170);
	set("coor/y", 110);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
