// Room: /d/yanping/gubao.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "�ű�");
	set("long", @LONG
���������������ر��������죬�ؿ�Ϊʯ���ţ�����һľ��ͤ鿺�
�δ���ʯ���ű����������Ҵ���ͳ����������޹ŵ�����������ѡ����
�����ѡ�ľ�ҡ��ű����湰��ǰ������ǧ����ɼ���ഫ������õ��ڱ���
�����˵㻯�������ڴˣ���֦Ҷ��չ����ب���εΪ׳�ۣ���ʹԶ��
��ƽ�Ƕ���Ҳ��Ƴ����ͦ�����Ƶ����ˡ����ٿ������ɱ���Ⱥɽ��ɫ��
����Զ�������������۴��αȣ�����֮ˮ���������ƣ�������ΰ������
Ի���������ճ�����ƽ�ǹ���Ѥ����ĺ��Ϧ�䣬������������ϼ����
LONG );
	set("exits", ([
		"west"      : __DIR__"mangdangshan",
		"southwest" : __DIR__"yanxianshan",
		"northdown" : __DIR__"yidao2",
		"southdown" : __DIR__"banyanting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
