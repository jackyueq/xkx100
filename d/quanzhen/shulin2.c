// /d/quanzhen/shulin2.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��λ������ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ��
�ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦
ͷ��Ͷ����¡�ż��Զ�������޺�����������һ�����ظС���������
��������һ��С����
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northwest"  : __DIR__"shenheyuan",
                "east"       : __DIR__"baoziyan",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/deer": 1,
        ]));
	set("coor/x", -3160);
	set("coor/y", 60);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
