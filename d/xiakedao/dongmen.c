// dongmen.c ����

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǰͻȻһ������ǰ��Ȼ����һ����ʯ���ɵĶ��ţ��Ŷ�
�ϵ�����������ӭ���ݣ�����ʯ�������̷��֪�����Ŷ�������
�ɽ�����Ѫ�ۣ������ֳ����˵ĸ��к��ݳޡ�
LONG );
        set("exits", ([
                "enter" : __DIR__"yingbin",
                "west" : __DIR__"shidong1",
        ]));
        set("objects", ([
                __DIR__"npc/dizi1" : 1]));
	set("coor/x", -3090);
	set("coor/y", -22080);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}