// Room: /d/qilian/ailaoshan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
��ɽ������������ݲ�����һ��̤��ɽ��, �ٸ�һ��Ī����״�Ĺ�
��֮Ϣ����˵�е������������ɱ��ۣ�û�гɹ�����ۿ�������ͷ��
��������Ϊ�죬˫��ΪĿ�������������ս��ʧ���ᱻ��춴�ɽ��
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"southeast" : __DIR__"tieshishan",
		"southwest" : __DIR__"zibaipo",
	]));
	set("no_clean_up", 0);
	set("coor/x", -13500);
	set("coor/y", 3500);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}