// /d/quanzhen/shulin3.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��λ������ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ��
�ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦
ͷ��Ͷ����¡�ż��Զ�������޺�����������һ�����ظС��������ϡ�
�Ͷ�����һ��С����
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "south"    : __DIR__"shenheyuan",
                "northup"  : __DIR__"juyan",
                "eastdown" : __DIR__"heifengdong",
        ]));

	set("coor/x", -3170);
	set("coor/y", 80);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
