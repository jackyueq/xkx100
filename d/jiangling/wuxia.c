//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "��Ͽ");
	set ("long", @LONG
��Ͽ��Խ��������ʡ������Ͽ����Ϊ����������һ��Ͽ�ȣ����ε�
�±��ɲ�κܱ��İ�ɫ�Ҳ���ɣ�����ǳ���������������Ŵ���ʿͷ
���Ľ���������ֽн������Ͽ�����Σ��������±��ѷ��з��к�ɫ��
���ף���˽�����Ͽ�����˵����Ͽ��һ��բ�ţ���ô��Ͽ��ֱ����
һ���ػ����۵����ȡ�����ɽ����һ�䣬��һת��ÿһ����ÿһ�ۣ���
����չ��һ�����õķ羰������������������Ͽ������������Ͽ���ϱ�
��һ���š�
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
                "west" : __DIR__"qutangxia",
                "east" : __DIR__"xilingxia",
                "south": __DIR__"dangyangqiao",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
