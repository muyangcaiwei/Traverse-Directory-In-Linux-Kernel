int lsDir(){

	struct list_head* plist;
	struct file* dir=NULL;
	char path[] = "/mnt/media_rw";

	dir = filp_open(path, O_RDWR, 0);
  if(IS_ERR(dir)){
    return -1;
  }
	list_for_each(plist,&(dir->f_path.dentry->d_subdirs))
	{
		struct dentry* temp=list_entry(plist,struct dentry,d_child);
		if(temp)
		if(temp->d_inode)
		if(d_count(temp))
		{       
			printk("find dir:%s\n",temp->d_name.name);
		}    
	}
  
  return 0;
}
