// Room: /d/yanping/yanxianshan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
��˵������ƽ���ܿͽ�®�ڴ������ɷ𡣴˴�����Σ����ᾣ���ľ
��ε��ɽ�����ף���Ȫˬ�ˣ���ɫ����������������Ϊ����´��ϼ����
��Ϊ��ƽ�˾�֮һ��ʫ����֮Ի�������˺�ȥס��������ɽǰ���쿪��
���ã�������¯�̡���
�����ұ���ΡȻ������һ���ɶ��칤����Ȼʯ�𣬸�Լ���ɣ�ͷ�Ը��ӡ�
���䱳���ɽ´�ϣ����п�����ʽʯ��Ŀ��ҡ�
LONG );
	set("exits", ([
		"northeast" : __DIR__"gubao",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1480);
	set("coor/y", -6120);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
