// Room: /d/yueyang/qiuyueting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ͤ�������š����¾��Գ������γ�������������������˾���
֮����ͥ���¡�����ƹʡ�����ͤ���ھ�ɽ����Сɽ�������ϣ�ʼ����
��ĩ��Ϊ������������ͤ��ͤ�������˹���̨��վ��ͤ�Ͽ��Ա�����ͥ
����ɫ(moon)����˵�������������������������������ͥ���¡���
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("item_desc", ([
		"moon" : "
    ���µĶ�ͥ����Ȼ������������ĵ�����Ů����������������
ǣ��������ִ�������˺�������һ��������컯���Ƕ�ͥ������ҹ��
չʾ��������������һ�������֮�����������������ڡ�\n"
	]));
	set("exits", ([
		"southdown" : __DIR__"qiuyueqiao",
		"northeast" : __DIR__"xiaolu8",
	]));
	set("coor/x", -1670);
	set("coor/y", 2340);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
