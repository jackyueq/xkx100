//      shenghu.c ʥ��

inherit ROOM;

void create()
{
        set("short","ʥ��");
        set("long",@LONG
��ǰ����������ʥ���������ĺ��浹Ӱ������Ͱ��ƣ�����ˮ��
�����Ŀ�������Զ����̻Ի͵�ѩɽ�������ɼ�����Զ���Ǽ��������
��ѩɽ��������ߴ������ɽ���ഫɽ�������ɾ�ס��ѩɽ���ڻ���ѩ
ˮ��������С�
LONG );
        set("resource/water",1);
	set("outdoors", "xueshan");
        set("exits",([
                "south" : __DIR__"tulu3",
                "east"  : __DIR__"hubian1",
		"west"  : "/d/npc/m_weapon/liangunshi",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30020);
	set("coor/y", -8010);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
