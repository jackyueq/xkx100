// /d/quanzhen/shulin4.c
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
                "southup"   : __DIR__"shandao2",
                "north"     : __DIR__"shulin5",
        ]));
        set("objects", ([
                "/d/wudang/npc/bee" : 1,
        ]));
	set("coor/x", -3190);
	set("coor/y", 140);
	set("coor/z", 110);
	setup();
        replace_program(ROOM);
}
