// smallbox.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("С����", ({"small box", "box"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
        	set("long",
"��ֻ����С�öֻ࣬һ�߼���������һ�ż���д��������
���Һ����ߣ����Һ��ǣ��������ر������������п���ʱ
�ж���������������׵�ͼ���٣����о綾���Գ�̰����
ͽ�������ڴ�С�����ڡ���\n");
        	set("unit", "ֻ");
        	set("open_count", 1);
        	set("weight", 1000);
        }
}

void init()
{
        add_action("do_open","open");
}

int do_open()
{
  object ob, me = this_player();
  object ob1 ;
  ob1 = new(__DIR__"smallbox1");
  ob1 -> move(me);
	ob = new("/clone/book/jinshe1");
	if (ob->violate_unique())
	{
		destruct(ob);
		destruct(this_object());
		return notify_fail("�����Ѿ������˴򿪹��ˡ�\n");
	}
  message_vision(HIR 
"$N���ִ����У���������һ���飬��д���������š����֣���
ǯ�ӽҿ���ҳ����д������С�֣��������ͼ�����е��ǵ�ͼ��
�е����������ƣ�����Щ���л��ص�ͼ����\n" NOR, this_player());
  add("open_count", -1);
  ob -> move(me);
 	destruct(this_object());
  return 1;
}
