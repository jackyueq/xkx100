// /d/quanzhen/xiaohebian.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "С�ӱ�");
        set("long", @LONG
�˴�λ�����ɽ��һƫƧ����ֻ��Ũ���ѵأ����⸡������Χ��
�������ľ���ľ��ľ�֮������Զ����С����ɽ��(dong)��ӿ����Ȫ
ˮ���γɣ����ȵ�ˮ���������������˳����������ͨ��ɽ�����
�����ɽ���ɽ���С�
LONG
        );
        set("outdoors", "zhongnan");
        set("item_desc", ([
                "dong" : "һ�����䡢�İ����ֲ���Сɽ����\n",
        ]));
        set("exits", ([
                "enter" : __DIR__"shandong1",
                "north" : __DIR__"shanlu7",
        ]));

	set("coor/x", -3160);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
