// Room: /d/lingzhou/hut2.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ�䲻������ݣ����ϻ��кü������СС���ƶ�������͸��
��Щ��������㷢������տյ�����ͽ���ıڣ��ݶ��ͽ��������Щ��
��������֩�������ذ�Ҳ�������Ƴɣ�ͬ�������˻ҳ����������Ե���
�𰵡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"hut",
	]));
	set("no_clean_up", 0);
	set("coor/x", -17980);
	set("coor/y", 32130);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
