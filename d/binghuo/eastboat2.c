// Room: /binghuo/eastboat2.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�������沨ƽ�羵�����ں�Ÿ�����д��У�����緫��������
�졣ԶԶ�ɼ����ߺ�ƽ���ϣ��и��д�������С��������ǧ�̺��У�
��ʵ�̵ÿɰ���
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

