// Room: /d/nanshaolin/zhlou6.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
�ش�������һ����������ɽ�磬������ˡ������ɼ����ֵľ�ͷ��
ͷ���ϵ�¥�忪�˸��󶴣�����һ�ڴ��ӡ�������ֻ�ܿ������ӵ��±�
Ե������ڶ����ģ�ʲôҲ��������
LONG );
	set("exits", ([
		"up"   : __DIR__"zhlou7",
		"down" : __DIR__"zhlou5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

