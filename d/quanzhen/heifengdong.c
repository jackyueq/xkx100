// heifengdong.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�ڷﶴ");
        set("long", @LONG
�˴�λ�����ɽ��������̫��ɽ�ϡ�ֻ��ɽ��ֱ��ֱ�£�����
��Ķ��ͣ�ֻɽ������һ�������Ӵֵ�ʯ������ʱð��һ�ɺ�������
���µġ�������һƬ���֡�
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "westup"  : __DIR__"shulin3",
        ]));

	set("coor/x", -3160);
	set("coor/y", 80);
	set("coor/z", 80);
	setup();
        replace_program(ROOM);
}
