// yongdao2.c ��


inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
����һ���������������ߵ����͵ƣ������䰵��ȴҲ�ɱ��
·��������ɽ������Ȼ��Ѩ������ɣ��˴�����Ļ�Ȼ���ʣ���
�ܶ�Ľ��������ڴ���Ϣ��
LONG );
        set("exits", ([
               "south" : __DIR__"shidong1",
               "north" : __DIR__"yongdao1",
        ]));
        set("objects", ([
               "/d/huashan/npc/haoke" : 2,
        ]));
	set("coor/x", -3100);
	set("coor/y", -22070);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}