// Xiaoyao.c:  the sleeping room for Xingxiu
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "��ң��");
	set("long", @LONG
����������޵�������֮����ԭ��������һ�ֲڵ�ʯ������������
�޵��Ӳ������ɣ����˷�԰������������������ߡ���֪�ж�������Ů
�ڴ˰������գ��ȹ�������
    ���������˼��ų����Ĳݵ��ӡ������Ա���һЩ�ƾƹ��ӡ�����
(wall)����Щ�ּ���
LONG );
	set_light(0);
	set("sleep_room", "1");
	set("no_fight", "1");
	set("exits", ([
		"out" : __DIR__"shidao",
	]));
	set("item_desc", ([
		"wall" : "�����������˵ö���֮��\n\n         �ۣ�ˬ���ˣ�\n",
	]) );
	set("no_clean_up", 0);
	set("coor/x", -50200);
	set("coor/y", 20220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
