inherit ROOM;
void create()
{
        set("short", "�ƺ�");
        set("long", @LONG
������Ƕ����������ƺ��ˣ�������ȥ����ɽ��Ұ��
������������Ū�����Լ����ںγ������ܶ��ǳ�·��ʲ
ô�����������
LONG   );
	set("coor/x", -6200);
	set("coor/y", -1180);
	set("coor/z", 200);
	setup();
}
void init()
{
  object me = this_object();
  me->set("exits/east",__DIR__"yunhai"+random(3));
  me->set("exits/west",__DIR__"yunhai"+random(3));
  me->set("exits/north",__DIR__"yunhai"+random(3));
  me->set("exits/south",__DIR__"yunhai"+random(3));
}