// /d/quanzhen/shulin1.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��λ������ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ��
�ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦
ͷ��Ͷ����¡�ż��Զ�������޺�����������һ�����ظС���������
�ϸ���һ��С����
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "north"      : __DIR__"baoziyan",
                "southdown"  : __DIR__"shanlu9",
        ]));

	set("coor/x", -3150);
	set("coor/y", 50);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
