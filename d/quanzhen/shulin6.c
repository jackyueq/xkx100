// /d/quanzhen/shulin6.c
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
                "southup"   : __DIR__"shulin5",
                "northdown" : __DIR__"shandao3",
        ]));
        set("objects", ([
                "/d/wudang/npc/monkey" : 1,
        ]));
	set("coor/x", -3190);
	set("coor/y", 160);
	set("coor/z", 100);
	setup();
        replace_program(ROOM);
}
