// /d/quanzhen/shulin5.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��λ������ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ��
�ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦
ͷ��Ͷ����¡�ż��Զ�������޺�����������һ�����ظС���������
����һ��С����
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "south"     : __DIR__"shulin4",
                "northdown" : __DIR__"shulin6",
        ]));
	set("coor/x", -3190);
	set("coor/y", 150);
	set("coor/z", 110);
	setup();
        replace_program(ROOM);
}
