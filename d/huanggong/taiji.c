// Room: /d/huanggong/taiji.c

inherit ROOM;

void create()
{
	set("short", "̨��");
	set("long", @LONG
����޴��̨�����ڻʳǵ���������, ������̨��, �м������˵�
̺������. �����������һ������(gui)��һ������(liang). ����Χ��
�Ǻ�����������, �����ޱ�׳��. ����̨��ÿ�㶼����������, ����
���������˻���, �����Ϲ���һǧ�İ���ʮ�˸�����.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"taihedian",
	]));
	set("objects", ([
		__DIR__"npc/suke" :1,
	]));
        set("no_clean_up", 0);
	set("item_desc", ([
		"gui"   : "��ԭ��ʱ��ı�׼����, �ǻʵ��������������.\n",
		"liang" : "��ԭ���ݻ��ı�׼����, �ǻʵ۹�����˽���������ϵ�����.\n",
	]));
	set("coor/x", -200);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}